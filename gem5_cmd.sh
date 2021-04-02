#!/usr/bin/env bash
set -eu
gem5_path="~/lworkspace/mygem5/gem5_pyenv"

if [ $# -eq 1 ]; then
  test_bin="$1"
else
  echo "full path to an *.elf file must be provided as argument"
  exit
fi

cmd="""
${gem5_path}/build/ARM/gem5.opt \\
--debug-file=trace.txt \\
--debug-flags='Exec,GIC,VGIC' \\
${gem5_path}/configs/example/fs.py \\
--bare-metal \\
--kernel=${test_bin} \\
--machine-type=VExpress_GEM5_V1 \\
--mem-size=256MB
"""
echo "$cmd"
#eval "$cmd"
