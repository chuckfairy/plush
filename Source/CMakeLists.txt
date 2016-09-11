#find_package(MySQL REQUIRED)
#include_directories(${MYSQL_INCLUDE_DIR})
#target_link_libraries(mainexe ${MYSQL_LIBRARY})
#if( UNIX AND NOT APPLE )
  #set(rt_library rt )
#endif()

#find_package( Gperftools QUIET )
#if( GPERFTOOLS_FOUND )
    #message( STATUS "Found gperftools; compiling witness_node with TCMalloc")
    #list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
#endif()

# We have to link against graphene_debug_witness because deficiency in our API infrastructure doesn't allow plugins to be fully abstracted #246

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PATH (MYSQL_INCLUDE_DIR mysql/mysql.h
		$ENV{MYSQL_INCLUDE_DIR}
		$ENV{MYSQL_DIR}/include
		/usr/include/mysql
		/usr/local/include/mysql
		/opt/mysql/mysql/include
		/opt/mysql/mysql/include/mysql
		/opt/mysql/include
		/opt/local/include/mysql5
		/usr/local/mysql/include
		/usr/local/mysql/include/mysql
        /usr/lib/mysql
		$ENV{ProgramFiles}/MySQL/*/include
		$ENV{SystemDrive}/MySQL/*/include)

FIND_LIBRARY (MYSQL_LIB NAMES mysqlclient_r
		 PATHS
		 $ENV{MYSQL_DIR}/libmysql_r/.libs
		 $ENV{MYSQL_DIR}/lib
		 $ENV{MYSQL_DIR}/lib/mysql
		 /usr/lib/mysql
		 /usr/local/lib/mysql
		 /usr/local/mysql/lib
		 /usr/local/mysql/lib/mysql
		 /opt/local/mysql5/lib
         /usr/lib/mysql
		 /opt/local/lib/mysql5/mysql
		 /opt/mysql/mysql/lib/mysql
		 /opt/mysql/lib/mysql)

FIND_LIBRARY (MYSQL_LIB NAMES mysqld
		 PATHS
		 $ENV{MYSQL_DIR}/libmysql_r/.libs
		 $ENV{MYSQL_DIR}/lib
		 $ENV{MYSQL_DIR}/lib/mysql
		 /usr/lib/mysql
		 /usr/local/lib/mysql
		 /usr/local/mysql/lib
		 /usr/local/mysql/lib/mysql
		 /opt/local/mysql5/lib
		 /opt/local/lib/mysql5/mysql
		 /opt/mysql/mysql/lib/mysql
		 /opt/mysql/lib/mysql)

IF (MYSQL_LIB)
	GET_FILENAME_COMPONENT (MYSQL_LIB_DIR ${MYSQL_LIB} PATH)
ENDIF (MYSQL_LIB)

IF (MYSQL_INCLUDE_DIR AND MYSQL_LIB_DIR)
	SET(MYSQL_FOUND TRUE)

	INCLUDE_DIRECTORIES (${MYSQL_INCLUDE_DIR})
	LINK_DIRECTORIES (${MYSQL_LIB_DIR})

	SET(MYSQL_CLIENT_LIBS mysqlclient_r mysqld)

ELSE (MYSQL_INCLUDE_DIR AND MYSQL_LIB_DIR)
	MESSAGE(FATAL_ERROR "Cannot find MySQL. Include dir: ${MYSQL_INCLUDE_DIR}  library dir: ${MYSQL_LIB_DIR}")
ENDIF (MYSQL_INCLUDE_DIR AND MYSQL_LIB_DIR)

FIND_PACKAGE (Boost 1.40.0 REQUIRED COMPONENTS
	thread
system)

INCLUDE_DIRECTORIES (
	${MYSQL_INCLUDE_DIR}/mysql
	${MYSQL_INCLUDE_DIR}/mysql/private
	${Boost_INCLUDE_DIRS})

LINK_DIRECTORIES (
	${MYSQL_LIB_DIR}
${Boost_LIBRARY_DIRS})

add_executable( connection main.cpp )

add_executable( http_test App.cpp )

target_link_libraries( connection
    PUBLIC mysqlclient mysqlcppconn )

target_link_libraries( http_test
    PUBLIC mysqlclient mysqlcppconn cpprest )

install( TARGETS
   connection

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

install( TARGETS
    http_test

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
