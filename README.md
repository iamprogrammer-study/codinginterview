# 나프다 코딩인터뷰 스터디

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
    upstream git@github.com:iamprogrammer-study/codinginterview.git (fetch)
    upstream git@github.com:iamprogrammer-study/codinginterview.git (push)
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
