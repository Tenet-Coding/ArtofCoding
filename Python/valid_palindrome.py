def isPalindrome(s: str) -> bool:
        string = s.lower()
        i = 0
        j = len(s) - 1
        flag = 0
        while i < j:
            if((ord(string[i]) >= 97 and ord(string[i]) <= 122) or (ord(string[i]) >= 48 and ord(string[i]) <= 57)):
                if((ord(string[j]) >= 97 and ord(string[j]) <= 122) or (ord(string[j]) >= 48 and ord(string[j]) <= 57)):
                    if ord(string[i]) != ord(string[j]):
                        flag = 1
                        break
                    i += 1
                    j -= 1
                else:
                    j -= 1
            else:
                i += 1
        if flag == 1:
            return False
        return True
