from bcc import BPF

# 定义 eBPF 程序, 使用 C 语言编写
program = r"""
int hello(void *ctx) {
    // 打印输出信息
    bpf_trace_printk("Hello eBPF!");
    return 0;
}
"""

# 初始化 BPF 对象, 将 C 语言程序交给 bcc 处理
b = BPF(text=program)

# 获取 execve 系统调用的函数名
syscall = b.get_syscall_fnname("execve")

# 将 eBPF 程序挂载到 execve 系统调用上
b.attach_kprobe(event=syscall, fn_name="hello")

# 输出日志信息
b.trace_print()
