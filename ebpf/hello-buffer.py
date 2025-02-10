from bcc import BPF

# 定义 eBPF 程序
program = r"""
BPF_PERF_OUTPUT(output);

struct data_t {
    int pid;
    int uid;
    char command[16];
};

int hello(void *ctx) {
    struct data_t data = {};

    // 获取当前进程的 PID
    data.pid = bpf_get_current_pid_tgid() >> 32;

    // 获取当前用户的 UID
    data.uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;

    // 获取当前进程的命令名
    bpf_get_current_comm(&data.command, sizeof(data.command));

    // 将数据提交到性能事件输出映射
    output.perf_submit(ctx, &data, sizeof(data));

    return 0;
}
"""

# 初始化 BPF 对象
b = BPF(text=program)

# 获取 execve 系统调用的函数名
syscall = b.get_syscall_fnname("execve")

# 将 eBPF 程序挂载到 execve 系统调用上
b.attach_kprobe(event=syscall, fn_name="hello")

# 定义处理性能事件的回调函数
def print_event(cpu, data, size):
    # 解析性能事件数据
    data = b["output"].event(data)
    print(f"{data.pid} {data.uid} {data.command.decode()}")

# 打开性能事件缓冲区并注册回调函数
b["output"].open_perf_buffer(print_event)

# 循环处理性能事件
while True:
    b.perf_buffer_poll()
