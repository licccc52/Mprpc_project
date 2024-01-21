# Mprpc_project

## 集群 : 每一台服务器独立运行一个工程的所有模块
## 分布式 : 一个工程拆分了很多模块, 每一个模块独立部署运行在一个服务器主机上, 所有服务器协同工作共同提供服务, 每一台服务器称作分布式的一个节点, 根据节点的并发要求, 对一个节点可以再做节点模块集群部署


## 单机版服务器瓶颈:
1. 受限于硬件资源, 聊天服务器所能承受的用户并发量不够
2. 任意模块的修改, 都会导致整个项目代码重新编译, 部署
3. 系统中,有些模块属于CPU密集型(计算量很大)-> 部署在CPU好的机器上, 有些模块属于I/O密集型(经常接收网络IO, 输入输出)-> 需要带宽好, 造成各模块对于硬件资源的需求是不一样的

## 集群服务器, 集群中的每一台服务器都独立运行一套系统
1. 用户并发量提升了
2. 类似后台管理这样的模块, 不需要高并发
3. 项目代码还是需要整体重新编译, 而且需要进行多次部署

## 分布式服务器 : 所有服务器共同构成一个聊天系统, 
1. 大系统的软件模块怎么划分? -> 可能会实现大量重复代码                              \  rpc
2. 各模块之间如何访问?  机器一上的模块怎么调用机器2上的模块的一个业务方法?           /


## protobuf =>> json
1. protobuf二进制存储; xml和json都是文本存储
2. protobuf不需要存储额外的信息

## 
1. ./bin 可执行文件
2. ./build CMake 构建编译项目文件
3. ./examle 使用框架的服务消费者
4. ./lib 库文件
5. ./src 源代码
6. ./test 测试