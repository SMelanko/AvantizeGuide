# Avantize Git Guide

Here is a guide how to start working with Git.

- [Avantize Git Guide](#avantize-git-guideline)
   - [Introduction](#introduction)
   - [First Steps](#first-steps)
   - [Braches](#branches)
   - [Workflow](#workflow)

## Introduction

   Git is a free and open source distributed version control system designed to handle everything from small to very large projects with speed and efficiency.

   We use [SmartGit](http://www.syntevo.com/smartgit/) as a graphical Git client which runs on all major platforms.

## First Steps

1. First of all you need public and private keys. Here is a [tutorial](https://docs.gitlab.com/ee/gitlab-basics/create-your-ssh-keys.html) (or [this one](https://help.github.com/articles/connecting-to-github-with-ssh/)) that provides instructions how to generate and add public ssh key to your GitLab account.
2. Then open [Your projects](https://git.avantize.com "Git Avantize") and go to your leaning project.
3. Copy URL for your learning repository.
<p align="center"></p>
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-1.png"/></p>
4. Launch SmartGit -> 'Repository' -> 'Clone...'.
<p align="center"></p>
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-2.png"/></p>
5. Paste your URL which was copied on the 3rd step and click 'Continue' button.
<p align="center"></p>
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-3.png"/></p>
6. On the Selection page click 'Continue' button.


7. Pass authentication to the git.avantize.com.

   If you made a passphrase before - enter it, else - leave this field empty.

<p align="center"></p>
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-4.png"/></p>
8. Specify the local directory and click 'Finish' button.
<p align="center"></p>
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/git/imgs/first-steps/img-5.png"/></p>
   Open folder from this item. Here will be your source files.

## Branches

   A branch represents an independent line of development. Branches serve as an abstraction for the edit/stage/commit process in Git. You can think of them as a way to request a brand new working directory, staging area, and project history.

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

   Note that you should use past simple or past simple passive forms for commit messages.
 
   If you have done a lot of changes just numerate them, for example:
   ```
   1. Fixed constructor of the Table class.
   2. Fixed code issues.
   3. ...
   ```

   And if you don't have any idea what you should write, use these tips:
   ```
   4. Code refactoring was made.
   5. Fixed code issues.
   6. Made bug fixes and code improvements.
   ```

## Workflow

