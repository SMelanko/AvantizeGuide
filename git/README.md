# Avantize Git Guide

Here is a guide how to start working with Git.

- [Avantize Git Guide](#avantize-git-guideline)
   - [Introduction](#introduction)
   - [First Steps](#first-steps)
   - [Braches](#branches)
   - [Commit](#commit)
   - [Push](#push)
   - [Merge Request](#merge-request)
   - [Pull](#pull)

## Introduction

   Git is a free and open source distributed version control system designed to handle everything from small to very large projects with speed and efficiency.

   We use SmartGit as a graphical Git client which runs on all major platforms.

## First Steps

1. First of all you need public and private keys. Here is a [tutorial](https://docs.gitlab.com/ee/gitlab-basics/create-your-ssh-keys.html) (or [this one](https://help.github.com/articles/connecting-to-github-with-ssh/)) that provides instructions how to generate and add public ssh key to your GitLab account.
2. Then open [Your projects](https://git.avantize.com "Git Avantize") and go to your leaning project.
3. Copy URL for your learning repository.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-1.png"/></p>
4. Launch SmartGit -> '_Repository_' -> '_Clone..._'.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-2.png"/></p>
5. Paste your URL which was copied on the 3rd step and click '_Continue_' button.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-3.png"/></p>
6. On the Selection page click '_Continue_' button.
7. Pass authentication to the git.avantize.com.

   If you made a passphrase before - enter it, else - leave this field empty.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-4.png"/></p>
8. Specify the local directory and click '_Finish_' button.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-5.png"/></p>
   Open folder from this item. Here will be your source files.

## Branches

   A branch represents an independent line of development. Branches serve as an abstraction for the edit/stage/commit process in Git. You can think of them as a way to request a brand new working directory, staging area, and project history.
   
1. Open SmartGit, select a project and navigate to the '_Branches_' widget. Right click on '_Local Branches_' item -> '_Add Branch..._'.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/branches/img-1.png"/></p>
2. Name your local branch.

<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/branches/img-2.png"/></p>

   Please note we use pattern for naming of branches.
   ```
   feature/branch-name
   ```
   For example:
   ```
   feature/settings
   feature/qt-integration
   feature/users-and-roles
   ```
   1-3 words always enought to name a branch for specific task.

## Commit

   A Commit command is used to save local changes in the local repository.
   
1. Open SmartGit, select a project and navigate to the Files widget. Select files which you want to commit. Right click on selected files and press Commit... from menu.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/commit/img-1.png"/></p>
2. In the opened dialog you should describe that you have done and press Commit.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/commit/img-2.png"/></p>

   Please use past simple or past simple passive forms for commit.
 
   If you have done a lot of changes just numerate them, for example
   ```
   1. Fixed constructor of the Table class.
   2. Fixed code issues.
   3. ...
   ```

   If you don't know what you should write, use these tips
   ```
   n. Code refactoring.
   n. Fixed code issues.
   ```

3. There are two ways to go forward:
   * You decided to fix or add some code - repeat 1st and 2nd steps from this item.
   * You finished task - go to [Push](#push) item.

## Push
   
   A Push command is used to push the current branch or changes in all tracking branches to the remote repository.

1. All changes were commited and they are under your local branch. Time to push changes to the [server](git.avantize.com). Select current branch -> right click on it -> Push..
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/push/img-1.png"/></p>

   Now all changes on the remote repository. Go to the [Merge Request](#merge-request) item.

## Merge Request

   A Merge Request command is used to merge changes from your branch into develop branch.

1. If you haven't pushed changes to the server - just skip this item, else - open [remote repository](https://git.avantize.com) and go to your project.
2. Click Create Merge Request button (in the top-right corner).
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/merge-request/img-1.png"/></p>
3. Fill Title, Description fields, set Assignee (your supervisor) and click Submit merge request.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/merge-request/img-2.png"/></p>

   If everything okay and supervisor has approved your code then you switch to develop branch (Check Out...), make [Pull](#pull) and delete that branch.
   
   Else if you did some mistakes then you receive notifications which point you what you must fix. Fix them, [Commit](#commit) and [Push](#push) once again.

## Pull

   A Pull command incorporates changes from a remote repository into the current branch.
   
1. Open SmartGit and push Pull button (in the top-left corner).
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/pull/img-1.png"/></p>
2. Pass configuration settings (just leave everything by default) and press Configure.

   This dialog appears only once during configuration.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/pull/img-2.png"/></p>
3. And after all press Pull.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/pull/img-3.png"/></p>

   Now all files from the project must be updated.
