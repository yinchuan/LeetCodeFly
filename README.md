To create a local code file for a LeetCode question and to copy local code to LeetCode for submitting. To be used together with [LeetCodeSyncer](https://github.com/yinchuan/LeetCodesyncer).

# known issue
1. only support linux with `xclip` which is used to operate clipboard.

## Why?
Coding in LeetCode is not efficient.

# How?
LeetCodeSyncer extracts question data from description page and pastes to clipboard. `createFile.py` create a local file using data in clipboard. `upload.py` copy content of a local question to clipboard.

LeetCodeSyncer add two buttons("Download" and "Upload") to LeetCode editor next to "Run" button. "Download" extract question title, level, and given code from a questions description page. Those data are encoded in json and copied to system clipboard. "Upload" button pastes content of clipobard to Leetcode editor.

