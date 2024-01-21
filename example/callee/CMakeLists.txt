# 将该目录下的全部源文件都添加到变量名中
# aux_source_directory(. SRC_LIST)
# aux_source_directory(../src PROTO_LIST)
set(SRC_LIST userservice.cc ../user.pb.cc)

# 生成可执行文件所需要的源文件
# add_executable(provider ${SRC_LIST} ${PROTO_LIST})

#生成可执行文件 provider
add_executable(provider ${SRC_LIST}) 
# 需要链接的库
target_link_libraries(provider mprpc protobuf) 