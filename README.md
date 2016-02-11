# make

1.A makefile: rules
  A rule: target, prerequisites, commands
  targets: prereq1 prereq2
	  commands
  target: file to be made.
  prerequisites: files must exist 
  commands: shell commands to run(preceded by a tab)

2.make first evaluates prerequisites, then target.
  First rule is default to be evaluated first.
  If any prerequisite is newer(modified more recently) than the target, 
  the commands are run.
  If no prerequisites are listed to the right, then
  only the target(s) that do not exist are updated.
  (all, is updated by default)
	    
3.-l: indicates a library to be linked
  -l<NAME>, make searches libNAME.so, then libNAME.a

4.Make file can be called makefile, Makefile, or GNUMakefile.

5.--just-print(-n): tells make to display the commands it would execute 
  for a particular target without actually executing them.

6.Long lines can be continued using backslash (\)

7.comment: #

8.Wildcards(~, *, ?, [...], and [^...]) can be used in target, prerequisite, 
  or command

9.Phony target: targets that do not represent files, will always be executed.
  use a special target: .PHONY to define phony target:
  .PHONY: clean
  clean:
	rm -f *.o
  standard phony targets: all, install, clean, distclean, info, check

 
