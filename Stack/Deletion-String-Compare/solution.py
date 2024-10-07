class string(object):
    def hashtag(self,str1,str2):

        str1=[]
        str2=[]

        for char in str1:            
            if char =='#':
                if str1 !=[]:
                    str1.pop()

            else:
                str1.append(char)

        for char in str2:
            if char =='#':
                if str2 !=[]:
                    str2.pop()
            
            else:
                str2.append(char)
        return str1==str2