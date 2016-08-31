# 나프다 코딩인터뷰 스터디

## Disclaimer

이 [그룹](https://github.com/iamprogrammer-study/)과 [저장소](https://github.com/iamprogrammer-study/codinginterview)는 [나프다](http://iamprogrammer.io)의 실제 운영진과는 관련이 없으며 슬랙 채널 내에서 파생된 별도의 그룹입니다.

## 목차

1. 사용법
2. 문제 목록
3. 도움말
	- 업데이트

## 사용법

간단합니다. 이 리포지토리를 포크한 후, 자신의 깃허브 아이디를 앞에 붙여서 올린 후 풀 리퀘스트를 보내면 됩니다. 아토믹 커밋을 지향합니다 (1 커밋 당 1가지의 수정사항/풀이/작업 업로드).

언어의 제약은 없습니다. 문제는 자유롭게 추가하시되, 폴더명 규칙을 따라주시기 바랍니다.

## 문제 목록

1. **Single Number**: 정수로 이루어진 배열이 있는데, 단 하나만 빼고 다 두번 나옵니다. 그 하나를 찾아내시오. (출처: [leetcode 136번 문제](https://leetcode.com/problems/single-number/))
2. **Valid Parentheses**: 주어진 문자열은 소/중/대괄호의 조합입니다. 주어진 문자열이 유효한지 판단하시오. (출처: [leetcode 20번 문제](https://leetcode.com/problems/valid-parentheses/))
3. **Add Two Numbers**:  2개의 LinkedList의 값들을 위치별로 더해서 하나의 LinkedList를 생성하라. (출처: [leetcode 2번 문제](https://leetcode.com/problems/add-two-numbers/))
4. **Longest Common Subsequence**: 2개의 주어진 문자열에서 가장 긴 common subsequence를 구하시오. (출처: [Longest Common Subsequence](http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/)
5. **Minumum Depth of Binary Tree**: 주어진 바이너리 트리의 최소 깊이를 구하라. (출처: [leetcode 111번 문제](https://leetcode.com/problems/minimum-depth-of-binary-tree/))
6. **Two Sum**: 2개의 숫자를 더해서 sum를 만들 수 있는 인덱스를 찾아라. (출처: [leetcode 1번 문제](https://leetcode.com/problems/two-sum/))
7. **Min Stack**: 가장 작은 element를 상수시간에 구하는  스택을 구현하라. (출처: [leetcode 155번 문제](https://leetcode.com/problems/min-stack/))
8. **Next Permutation**: 주어진 순열의 다음 순열 구하라. (출처: [leetcode 31번 문제](https://leetcode.com/problems/next-permutation/))
9. **Invert Binary Tree**: 이진 트리를 뒤집어라 (출처: [leetcode 226번 문제](https://leetcode.com/problems/invert-binary-tree/))
10. **Path Sum**: 이진 트리에서 root-leaf에 이르는 경로의 값을 더해서 sum값이 되는 경로가 있는지 판단하라. (출처: [leetcode 112번 문제](https://leetcode.com/problems/path-sum/))
11. **Sum of Two Integers**: +/- 연산자를 사용하지 않고 두 정수의 합을 구하라. (출처: [leetcode 371번 문제](https://leetcode.com/problems/sum-of-two-integers/))
12. **Divide Two Integers**: *,/,mod 연산자를 사용하지 않고 두 정수의 나눔을 구하라. (출처: [leetcode 29번 문제](https://leetcode.com/problems/divide-two-integers/))
13. **Spiral Matrix**: m x n 행렬이 주어졌을때 나선형 순서로 모든 앨리먼트를 반환해라. (출처: [leetcode 54번 문제](https://leetcode.com/problems/spiral-matrix/))
14. **Permutations**: 주어진 숫자로 가능한 순열을 모두 리턴하라. (출처: [leetcode 46번 문제](https://leetcode.com/problems/permutations/))

## 도움말

### 업데이트

만약 포크해놓은 리포지토리를 업데이트해야한다면, 다음과 같은 방법을 사용하세요:

1. 이 리포지토리를 upstream 으로 추가합니다 ([출처](https://help.github.com/articles/configuring-a-remote-for-a-fork/)):

    ```
	$ git remote -v
    origin https://github.com/자신의_아이디/자신의_포크.git (fetch)
    origin https://github.com/자신의_아이디/자신의_포크.git (push)
    ```

	...라고 나오면, 이 리포지토리 역시 추가해주어야 합니다:

    ```
	$ git remote add upstream https://github.com/iamprogrammer-study/codinginterview.git
    ```

	이 리포지토리가 새로운 업스트림이 되었음을 확인합니다:

    ```
	$ git remote -v
    origin https://github.com/자신의_아이디/자신의_포크.git (fetch)
    origin https://github.com/자신의_아이디/자신의_포크.git (fetch)
    upstream https://github.com/iamprogrammer-study/codinginterview.git (fetch)
    upstream https://github.com/iamprogrammer-study/codinginterview.git (push)
    ```

2. upstream 리포지토리에 올라온 브랜치와 각각의 커밋들을 `fetch` 로 받아옵니다. `master`에 올라온 커밋은 `upstream/master` 이라는 로컬 브랜치에 저장됩니다 ([출처](https://help.github.com/articles/syncing-a-fork/)):

	```
    $ git fetch upstream
    remote: Counting objects: 75, done.
    remote: Compressing objects: 100% (53/53), done.
    remote: Total 62 (delta 27), reused 44 (delta 9)
    Unpacking objects: 100% (62/62), done.
    From https://github.com/iamprogrammer-study/codinginterview.git
	 * [new branch]      master     -> upstream/master
    ```

3. 자신의 포크에서 `master` 브랜치를 체크아웃 합니다:

    ```
    $ git checkout master
    Switched to branch 'master'
    ```

4. `upstream/master` 에서의 변경사항을 자신의 로컬 `master` 브랜치로 병합합니다. 이렇게 함으로서 업스트림 리포지토리의 내용을 자신의 포크의 `master` 브랜치와 (작업 내용을 잃지 않고) 동기화됩니다.

	```
    $ git merge upstream/master
    Updating a422352..5fdff0f
	Fast-forward
	 README                    |    9 -------
	 README.md                 |    7 ++++++
	 2 files changed, 7 insertions(+), 9 deletions(-)
	 delete mode 100644 README
	 create mode 100644 README.md
    ```

    만약 자신의 로컬 리포지토리에서 별다른 커밋이 없었다면, "fast-forward" 가 실행될 것입니다:

    ```
    $ git merge upstream/master
    Updating 34e91da..16c56ad
	Fast-forward
	 README.md                 |    5 +++--
	 1 file changed, 3 insertions(+), 2 deletions(-)
    ```
