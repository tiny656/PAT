class Contact(object):
    def __init__(self, name, birth, gender, phone, mobile):
        self.name = name
        self.birth = birth
        self.gender = gender
        self.phone = phone
        self.mobile = mobile


n = int(raw_input())
contacts = []
for i in xrange(n):
    inp = raw_input().split()
    contacts.append(Contact(inp[0], inp[1], inp[2], inp[3], inp[4]))
query = map(int, raw_input().split()[1:])
for q in query:
    if q < 0 or q >= len(contacts):
        print 'Not Found'
    else:
        c = contacts[q]
        print c.name, c.phone, c.mobile, c.gender, c.birth

    
    
