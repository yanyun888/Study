PROJ   = server
OBJS   = main.o Server.o ServerSocket.o LogThread.o StoreThread.o\
		 ClientThread.o LogQueue.o FileDao.o OracleDao.o 
CXX    = g++
RM     = rm -rf
CFLAGS = -c -Wall -I. -D_DEBUG
LIBS   = -lpthread #-lclntsh

$(PROJ):$(OBJS)
	$(CXX) $^ $(LIBS)-o $@
.cpp.o:
	$(CXX) $(CFLAGS) $^
clean:
	$(RM) $(OBJS)

