#!/bin/bash
# shell script to commit and push changes to my github repo
echo "Hello Snehel 😄"
echo "Enter the branch name"
read branch
git checkout -b $branch
git add .
echo "Enter the commit message: "
read msg
git commit -m "$msg"
git push origin $branch