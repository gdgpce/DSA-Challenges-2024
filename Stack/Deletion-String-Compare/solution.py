class string(object):
    def string_compare(self, s, t):
        str1=[]
        str2=[]

        for chara in s:
            if chara =='#':
                if len(str1)!=0:
                    str1.pop()
            else:
                str1.append(chara)
        
        for chara in t:
            if chara=='#':
                if len(str2)!=0:
                    str2.pop()
            else:
                str2.append(chara)
        return str1==str2

# Here string_compare takes s and t 2 strings as arguement, and then
# I have initialized 2 empty lists --> 'str1' and 'str2' to finally check after removing characters if there are any '#'s in strings,
# first for loop is to check every character in string 's',
# so here in this for loop what happens is- the characters in string 's' is iterated over to check whether any '#' is there,
# if any '#' is there it will be poped using str1.pop() method,
# if there are no '#'- the characters in the string 's' is appended to list 'str1'

# similarly second for loop also does the same thing as above for loop but here it checks with string 't',
# and does same as above

# finallly when the function 'string_compare' is called - 
# it returns - 'true' if both lists 'str1' and 'str2' have same characters
# otherwise it returns - 'false'