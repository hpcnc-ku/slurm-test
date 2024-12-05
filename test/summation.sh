#!/usr/bin/bash
#SBATCH --partition=batch 	### Partition
#SBATCH --job-name=test		### Job Name
#SBATCH --time=00:01:00		### WallTime (1 minute)
#SBATCH --nodes=1		### Number of nodes
#SBATCH --ntasks-per-node=2	### Number of Task (MPI processor) per node

mpirun -np $SLURM_NTASKS ./summation.out
