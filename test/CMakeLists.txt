cmake_policy(SET CMP0015 NEW)

aux_source_directory(. SRC_LIST)
list(REMOVE_ITEM SRC_LIST "./createRandomTest.cpp")

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CRYPTOPP_INCLUDE_DIRS})
include_directories(${JSONCPP_INCLUDE_DIRS})
include_directories(${JSON_RPC_CPP_INCLUDE_DIRS})
include_directories(..)

file(GLOB HEADERS "*.h")
add_executable(testeth ${SRC_LIST} ${HEADERS})
add_executable(createRandomTest createRandomTest.cpp vm.cpp TestHelper.cpp)

target_link_libraries(testeth ${Boost_UNIT_TEST_FRAMEWORK_LIBRARIES})
target_link_libraries(testeth ${CURL_LIBRARIES})
target_link_libraries(testeth ethereum)
target_link_libraries(testeth ethcore)
target_link_libraries(testeth secp256k1)
target_link_libraries(testeth solidity)
target_link_libraries(testeth webthree)

if (JSONRPC)
	target_link_libraries(testeth web3jsonrpc)
	target_link_libraries(testeth ${JSON_RPC_CPP_CLIENT_LIBRARIES})
endif()

target_link_libraries(createRandomTest ${Boost_UNIT_TEST_FRAMEWORK_LIBRARIES})
target_link_libraries(createRandomTest ethereum)
target_link_libraries(createRandomTest ethcore)
