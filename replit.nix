{ pkgs }: {
	deps = [
		pkgs.subversion
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}