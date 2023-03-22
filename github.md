Git Init AND Clone <br>
![git](../markdown/image/gitinit.png)

Using Git List
1. [git](https://git-scm.com/) + Choose VisualCode
2. git config --global user.name "Name"
3. git config --global user.email "you@example.com"
4. git bash -> ca ~/ssh + ssh-keygen + cat id_rsa.pub
5. [github](https://github.com/) -> Settings + SSH and GPG keys
6. Add new + Title + key + Add SSH key
7. Power shell -> Create Repositories 
   + git clone "local address" + echo "Hello world" > index.html 
   + git remote add origin "local address " 
   + git add . git commit -a -m "markdown 
   + git push origin main 
<br>

Setting Structure
1. git init "Name"
2. cd Name + git config (user.name + user.email)
3. git branch -b "Name" -> 새로운 브랜치 만들고
    git checkout "Name" -> 새로운 브랜치 이동 <br>
4. git pull origin main OR git merge "Name" __[commit]__
5. git add + git commit -a -m + git push

Remove [Git log] AND [Git push]
- git reset HEAD^ + git push -f origin main 

git command
- [1]status + [2]remote + [3]checkout + [4]merge + [5]pull 