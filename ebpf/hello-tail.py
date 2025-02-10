from bcc import BPF
import ctypes as ct

# 定义 eBPF 程序
program = r"""
BPF_PROG_ARRAY(syscall, 500);

int hello(struct bpf_raw_tracepoint_args *ctx) {
    int opcode = ctx->args[1];
    syscall.call(ctx, opcode);
    bpf_trace_printk("Another syscall: %d", opcode);
    return 0;
}

int hello_exec(void *ctx) {
    bpf_trace_printk("Executing a program");
    return 0;
}

int hello_timer(struct bpf_raw_tracepoint_args *ctx) {
    int opcode = ctx->args[1];
    switch (opcode) {
        case 222:
            bpf_trace_printk("Creating a timer");
            break;
        case 226:
            bpf_trace_printk("Deleting a timer");
            break;
        default:
            bpf_trace_printk("Some other timer operation");
            break;
    }
    return 0;
}

int ignore_opcode(void *ctx) {
    return 0;
}
"""

# 初始化 BPF 对象
b = BPF(text=program)

# 挂载 eBPF 程序到原始跟踪点
b.attach_raw_tracepoint(tp="sys_enter", fn_name="hello")

# 加载 BPF 函数
ignore_fn = b.load_func("ignore_opcode", BPF.RAW_TRACEPOINT)
exec_fn = b.load_func("hello_exec", BPF.RAW_TRACEPOINT)
timer_fn = b.load_func("hello_timer", BPF.RAW_TRACEPOINT)

# 获取程序数组映射
prog_array = b.get_table("syscall")

# 初始化程序数组, 忽略所有系统调用
for i in range(len(prog_array)):
    prog_array[ct.c_int(i)] = ct.c_int(ignore_fn.fd)

# 设置特定系统调用的处理函数
prog_array[ct.c_int(59)] = ct.c_int(exec_fn.fd)
prog_array[ct.c_int(222)] = ct.c_int(timer_fn.fd)
prog_array[ct.c_int(223)] = ct.c_int(timer_fn.fd)
prog_array[ct.c_int(224)] = ct.c_int(timer_fn.fd)
prog_array[ct.c_int(225)] = ct.c_int(timer_fn.fd)
prog_array[ct.c_int(226)] = ct.c_int(timer_fn.fd)

# 输出日志信息
b.trace_print()
