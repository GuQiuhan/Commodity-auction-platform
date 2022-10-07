1. 报错:
error while building/deploying project test (kit: desktop (x86-darwin-generic-mach_o-32bit)) the kit desktop (x86-darwin-generic-mach_o-32bit) has configuration issues which might be the root cause for this problem.

原因:路径中涉及的文件夹不能含有中文!!!

2. 文件路径记得修改,编译之前查看txt文件格式光标是否正确

3.在终端中运行：
source ~/.bash_profile   //这一步不一定需要，若显示qmake命令不可使用，就输入这一行命令
qmake proj1.pro
make
open *proj1*   //这一步是为了运行proj1.app