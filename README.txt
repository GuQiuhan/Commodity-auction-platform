1. 报错:
error while building/deploying project test (kit: desktop (x86-darwin-generic-mach_o-32bit)) the kit desktop (x86-darwin-generic-mach_o-32bit) has configuration issues which might be the root cause for this problem.

原因:路径中涉及的文件夹不能含有中文!!!

2. 文件路径记得修改,编译之前查看txt文件格式光标是否正确

3.在终端中运行：
source ~/.bash_profile   //这一步不一定需要，若显示qmake命令不可使用，就输入这一行命令
qmake -o Makefile proj1.pro //根据写好的proj1.pro生成makefile，同时自动的包含moc和uic的连编规则
make //编译
open *proj1.app*   //直接运行proj1.app
//open *proj1* //打开qt并且运行proj1.app

4.提交github步骤：
git add .
git commit -m "···"
git push -f origin master

5.运行步骤：将此文件夹拖至桌面运行即可。不要修改任何文件名。

6. 具体打包成dmg有待实现
