# Specialized_Vehicle_2024
Specialized unmanned vehicles project

1.	Github注册
——URL <https://github.com>

2.	Github安装
	Windows安装包下载
——URL<https://desktop.github.com>
	Linux下载命令
——终端输入：
<sudo apt-get update>
<sudo apt-get install git>

3.	Github登录
——终端输入：
<git config --global user.name "name">
<git config --global user.email " xxx@xxx.com">

4.	文件夹初始化
——终端输入：
<git clone https://github.com/KaiLiu20240205/Specialized_Vehicle_2024.git>

5.	获得git push权限
——终端输入：
	<git remote rm origin> #删除原本地仓库HTTP链接方式
	<git remote add origin git@github.com:KaiLiu20240205/Specialized_Vehicle_2024.git
> #建立本地仓库与github仓库之间的连接
	<ssh-keygen -t rsa -C "xxx@xxx.com"> #然后一直回车
<cat id_rsa.pub> #复制cat的结果发给我即可

6.	仓库迭代（只迭代负责部分即可）
——终端输入：
	<git add {& Specialized_Vehicle path}/Planning> #规划只需要更新Planning文件夹，各部分只需要更新自己负责的文件夹即可
	<git commit –m “注释”> #将更新部分提交至远程仓库，注释部分注明该版本修改内容即可
<git push origin main> #将远程仓库文件，提交至Github仓库main分支



