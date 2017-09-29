# Git handbook

## Basics
```bash
# init, clone, fetch, pull
git init #to initialize a local git repo
git clone https://github.com/tgogos/[name].git
git remote update
git pull origin master
git pull --all  # pull all remote branches
git fetch --all # fetch all remote branches

# check status, add changes, commit, push
git status
git add [filename]
git add .     # commonly used to add everything that was changed to the staging area
git add --all # like the above
git commit -m "short message goes here..."
git commit -m "short message goes here..." -m "long description goes here (optional)..."

# The -u tells Git to remember the parameters,
# so that next time we can simply run "git push" and Git will know what to do.
git push -u origin master

# remove file:
# wildcards can also be used, for example '*.txt' / don't forget using quotes
git rm [filename]

# commit history
git log

# diff of the most recent commit
git diff HEAD^ HEAD

# see the changes you just staged
git diff --staged

# unstage files
git reset [FILE]

# undo last commit, put changes into staging
git reset --soft HEAD^
# change the last commit
git commit --amend -m "New message"

# undo last commit and all changes
git reset --hard HEAD^

# undo last 2 commits and all changes
git reset --hard HEAD^^

```


## Before "staging"

> **important:** Be careful when using `git checkout -- ` because you might lose your work if the files have not been staged first. Read more about this at: [Can git undo a checkout of unstaged files?](http://stackoverflow.com/questions/2689265/can-git-undo-a-checkout-of-unstaged-files) 

```bash
# discard changes
# (File will be changed back to how it was at the last commit)
git checkout -- [FILE]

# discard all changes
git checkout -- .
```

## After "staging"
### HOW TO REMOVE FROM STAGING AREA (WHAT IS THE OPPOSITE OF GIT ADD)

Let's say that you have made changes to a couple of files, used `git add .` and now you are ready to commit your changes.
But then you think that it might be better to use more than one commits and group your files according to the reason they were changed. You can remove files from the staging area by using 
```bash
git reset <file>
```



## Branches
```bash
# show both REMOTE and LOCAL branches
git branch -a

# show REMOTE branches
git branch -r

# show LOCAL branches
git branch

# show CURRENT branch
git show-branch --current

# create branch
git branch [NAME]

# switch branch
git checkout [NAME]

# merge branch
# example: go to 'master' and merge 'develop' into it
#    git checkout master
#    git merge develop
git merge [NAME]

# delete branch
git branch -d [NAME]
```


## Submodules
```bash
# add
git submodule add [git repo url]

# pull latest commit
git submodule update --recursive --remote
git pull --recurse-submodules
```

	

## Misc
```bash	
# print your username
git config user.name

```
