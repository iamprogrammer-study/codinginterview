
def longestCommonSubsequence(str1, str2):
	s1 = set()
	for a in str1:
		s1.add(a)
	s2 = set()
	for a in str2:
		s2.add(a)
	return ''.join(s1 & s2)

print longestCommonSubsequence('ABCDGH', 'AEDFHR')
print longestCommonSubsequence('AGGTAB', 'GXTXAYB')
