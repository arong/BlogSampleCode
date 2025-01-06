# [优雅处理任务取消: C++20 的 Cooperative Cancellation](https://blog.csdn.net/arong_xu/article/details/144966700)

C++20 提供的 stop_token, stop_source 和 stop_callback 通过协作式机制实现了任务取消的灵活管理, 使得异步和并发编程更加优雅, 高效和可靠.

## 环境要求

- 编译器需要支持 C++20 标准

## 编译

```bash
mkdir build
cd build && cmake ..
cmake --build .
```
