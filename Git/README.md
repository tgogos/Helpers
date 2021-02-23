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
git log --diff-filter=A -- foo.js #find commit where file was added

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

# [learngitbranching.js.org](https://learngitbranching.js.org/)

## Git Branches
Branches in Git are incredibly lightweight as well. They are simply pointers to a specific commit -- nothing more. This is why many Git enthusiasts chant the mantra:

> *branch early, and branch often*

Because there is **no storage / memory overhead** with making many branches, it's easier to **logically divide up your work** than have big beefy branches.


## Branches and Merging
The first method to combine work that we will examine is git merge. Merging in Git creates a special commit that has two unique parents. A commit with two parents essentially means *"I want to include all the work from this parent over here and this one over here, and the set of all their parents."*


## Git Rebase
The second way of combining work between branches is rebasing. Rebasing essentially takes a set of commits, "copies" them, and plops them down somewhere else.

While this sounds confusing, the advantage of rebasing is that it can be used to make a **nice linear sequence of commits**. The commit log / history of the repository will be a lot cleaner if only rebasing is allowed.


## HEAD
First we have to talk about "HEAD". HEAD is the symbolic name for the currently checked out commit -- it's essentially what commit you're working on top of.

HEAD always points to the most recent commit which is reflected in the working tree. Most git commands which make changes to the working tree will start by changing HEAD.

Normally HEAD points to a branch name (like bugFix). When you commit, the status of bugFix is altered and this change is visible through HEAD.

## Detaching HEAD
Detaching HEAD just means attaching it to a commit instead of a branch.


## Relative Refs
Moving around in Git by specifying commit hashes can get a bit tedious. In the real world you won't have a nice commit tree visualization next to your terminal, so you'll have to use git log to see hashes.

Furthermore, hashes are usually a lot longer in the real Git world as well. For instance, the hash of the commit that introduced the previous level is `fed2da64c0efc5293610bdd892f82a58e8cbc5d8`. Doesn't exactly roll off the tongue...

The upside is that Git is smart about hashes. It only requires you to specify enough characters of the hash until it uniquely identifies the commit. So I can type `fed2` instead of the long string above.

With relative refs, you can start somewhere memorable (like the branch bugFix or HEAD) and work from there.

Relative commits are powerful, but we will introduce two simple ones here:

 - Moving upwards one commit at a time with `^`
 - Moving upwards a number of times with `~<num>`

Examples:

 - `git checkout master^`
 - We can travel backwards in time with `HEAD^`:
 
    ```
    git checkout fed2
    git checkout HEAD^
    git checkout HEAD^
    git checkout HEAD^
    ```
 - `git checkout HEAD~4`


## Reversing Changes in Git
There are many ways to reverse changes in Git. And just like committing, reversing changes in Git has both a low-level component (staging individual files or chunks) and a high-level component (how the changes are actually reversed). Our application will focus on the latter.

There are two primary ways to undo changes in Git -- one is using `git reset` and the other is using `git revert`.

## Git Reset

`git reset` reverts changes by moving a branch reference backwards in time to an older commit. In this sense you can think of it as "rewriting history;" `git reset` will move a branch backwards as if the commit had never been made in the first place. Example command:

 - `git reset HEAD~1`

## Git Revert

While reseting works great for local branches on your own machine, its method of "rewriting history" **doesn't work for remote branches** that others are using.

In order to reverse changes and share those reversed changes with others, we need to use `git revert`. Example command:

 - `git revert HEAD`


<br>
<br>
<br>
<br>
---
<br>
<br>
<br>
<br>


## `origin` & `upstream` workflow

- `origin` can be a fork of a repository which is now under **your personal** github account
- `upstream` can be the repository of your company / organization where you have to do pull-requests

The `.git/config` of your local repo contains something like this:

```
[remote "origin"]
	url = https://github.com/tgogos/[repo_name]
	fetch = +refs/heads/*:refs/remotes/origin/*
...
[remote "upstream"]
	url = https://github.com/[company/org]/[repo_name]
	fetch = +refs/heads/*:refs/remotes/upstream/*
```

### Sync your fork with `upstream`

More details:
 - [How do I update a GitHub forked repository?](https://stackoverflow.com/questions/7244321/how-do-i-update-a-github-forked-repository)
 - [Syncing a fork](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)

Summary / steps:

```
# Step 1: fetch
git fetch upstream

# Step 2: merge
git checkout master
git merge upstream/master

# Step 3: push
git push
```

