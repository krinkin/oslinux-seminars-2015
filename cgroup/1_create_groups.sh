#!/bin/bash

cgcreate -t kkv:kkv -g cpuset:/seminar/cpuset
cgcreate -t kkv:kkv -g cpu:/seminar/cpu
cgcreate -t kkv:kkv -g memory:/seminar/memory
cgcreate -t kkv:kkv -g cpuacct:/seminar/cpuacct
cgcreate -t kkv:kkv -g freezer:/seminar/freezer

cgcreate -t kkv:kkv -g cpuset:/seminar/cpuset1
cgcreate -t kkv:kkv -g cpu:/seminar/cpu1
cgcreate -t kkv:kkv -g memory:/seminar/memory1
cgcreate -t kkv:kkv -g cpuacct:/seminar/cpuacct1
cgcreate -t kkv:kkv -g freezer:/seminar/freezer1

cgset -r cpuset.cpus=0   /seminar/cpuset
cgset -r cpuset.cpus=2-3 /seminar/cpuset1



