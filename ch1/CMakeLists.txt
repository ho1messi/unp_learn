AUX_SOURCE_DIRECTORY (../lib/ Lib)

FIND_PACKAGE (Threads)

ADD_EXECUTABLE (daytimetcpcli daytimetcpcli.c ${Lib})
ADD_EXECUTABLE (daytimetcpsrv daytimetcpsrv.c ${Lib})

TARGET_LINK_LIBRARIES (daytimetcpcli ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES (daytimetcpsrv ${CMAKE_THREAD_LIBS_INIT})
