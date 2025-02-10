from bcc import BPF
from time import sleep

# 定义 eBPF 程序
program = r"""
BPF_HASH(counter_table);

int hello(void *ctx) {
    u64 uid;
    u64 counter = 0;
    u64 *p;

    // 获取当前用户的 UID
    uid = bpf_get_current_uid_gid() & 0xFFFFFFFF;

    // 在 Hash 表中查找该 UID 的计数器
    p = counter_table.lookup(&uid);
    if (p != NULL) {
        counter = *p;
    }

    // 计数器加 1
    counter++;

    // 更新 Hash 表中的计数器
    counter_table.update(&uid, &counter);

    return 0;
}
"""

# 初始化 BPF 对象
b = BPF(text=program)

# 获取 execve 系统调用的函数名
syscall = b.get_syscall_fnname("execve")

# 将 eBPF 程序挂载到 execve 系统调用上
b.attach_kprobe(event=syscall, fn_name="hello")

# 每隔 3 秒打印一次计数器信息
while True:
    sleep(3)
    result = []
    for k, v in b["counter_table"].items():
        result.append({"UID": k.value, "Count": v.value})
    print(result)
