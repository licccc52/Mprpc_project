aux_source_directory(. SRC_LIST)

add_library(mprpc ${SRC_LIST}) # 生成mprpc库
target_link_libraries(mprpc muduo_net muduo_base pthread)