
def longestCommonSubsequence1(str1, str2):
	s1 = set()
	for a in str1:
		s1.add(a)
	s2 = set()
	for a in str2:
		s2.add(a)
	return ''.join(s1 & s2)

def longestCommonSubsequence2(str1, str2):
	kCharMax = 255
	arr1 = []
	arr2 = []
	for i in range(0, kCharMax):
		arr1.append(0)
		arr2.append(0)

	for a in str1:
		arr1[ord(a)] = 1
	for a in str2:
		arr2[ord(a)] = 2

	result = ''
	for i in range(0, kCharMax):
		if arr1[i] == 1 and arr2[i] == 2:
			result = result + chr(i)
	return result

print longestCommonSubsequence1('ABCDGH', 'AEDFHR')
print longestCommonSubsequence2('ABCDGH', 'AEDFHR')

print longestCommonSubsequence1('AGGTAB', 'GXTXAYB')
print longestCommonSubsequence2('AGGTAB', 'GXTXAYB')
