## todo
1. extension -> local server -> files
2. extension -> filesystem
3. custom type in this question https://leetcode.com/problems/remove-duplicates-from-sorted-list/

## What?
This is a bookmarklet to sync code between LeetCode and a local file.

## Why?
Coding in LeetCode is not efficient.

## How?
### add code to bookmark

### run
1. find a question on LeetCode, click the bookmark
2. if all good, the bookmark puts a json in clipboard
3. `cd` to where you want to create the code file
4. run `python createFile.py [paste here]`
5. if all good, new code file will be in `<level>/<title>.cpp`

## issues