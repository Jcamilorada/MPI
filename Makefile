121: 121c
        mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/mpiOneToOne
121c:
        mpicc mpiOneToOne.c -o /shared/mpiOneToOne
ex41: example41
        mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile /shared/ex41
example41:
        mpicc mpiExample41.c -o /shared/ex41
ex42: example42
        mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile /shared/ex42
example42:
        mpicc mpiExample42.c -o /shared/ex42
ex71: example71
        mpirun --mca btl_tcp_if_exclude lo,eth0 -np 8 --hostfile machinefile /shared/ex71
example71:
         mpicc mpiExample71.c -o /shared/ex71