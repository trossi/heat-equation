#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef int MPI_Comm;
typedef int MPI_Datatype;
typedef int MPI_Status;
typedef int MPI_Info;
typedef int MPI_Op;

static inline MPI_Comm MPI_COMM_WORLD = -1;
static inline MPI_Status* MPI_STATUS_IGNORE = NULL;
static inline int MPI_PROC_NULL = -1;
static inline MPI_Info MPI_INFO_NULL = -1;
static inline int MPI_COMM_TYPE_SHARED = -1;
static inline MPI_Op MPI_SUM = -1;


static inline const MPI_Datatype MPI_DOUBLE = 10;

static inline size_t datatype_size(MPI_Datatype datatype) {
    switch (datatype) {
        case MPI_DOUBLE:
            return sizeof(double);
            break;
        default:
            printf("Type not implemented");
            exit(-1);
    }
}

static inline int MPI_Init(int *argc, char ***argv) {
    return 0;
}
static inline int MPI_Finalize() {
    return 0;
}

static inline int MPI_Abort(MPI_Comm comm, int errorcode) {
    abort();
}


static inline double MPI_Wtime() {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)t.tv_sec + 1.0e-9*t.tv_nsec;
}

static inline int MPI_Comm_size(MPI_Comm comm, int *size) {
    *size = 1;
    return 0;
}


static inline int MPI_Comm_rank(MPI_Comm comm, int *rank) {
    *rank = 0;
    return 0;
}

static inline int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
     int tag, MPI_Comm comm) {
    return 0;
}

static inline int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
     int source, int tag, MPI_Comm comm, MPI_Status *status) {
    return 0;
}

static inline int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
     int dest, int sendtag, void *recvbuf, int recvcount,
     MPI_Datatype recvtype, int source, int recvtag,
     MPI_Comm comm, MPI_Status *status) {
    return 0;
}

static inline int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
     MPI_Info info, MPI_Comm *newcomm) {
    return 0;
}

static inline int MPI_Comm_free(MPI_Comm *comm) {
    return 0;
}

static inline int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
     MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
    memcpy(recvbuf, sendbuf, count * datatype_size(datatype));
    return 0;
}

static inline int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
     void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
     MPI_Comm comm) {
    assert(sendtype == recvtype);
    assert(sendcount == recvcount);
    memcpy(recvbuf, sendbuf, sendcount * datatype_size(sendtype));
    return 0;
}
