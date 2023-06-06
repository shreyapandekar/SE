def telephone():
    phone_data=[]
    n=int(input("Enter number of clients:"))
    print("Enter phone number:")
    for i in range(n):
        x=int(input("->"))
        phone_data.append(x)
    return phone_data


def hashfunction1(key,size):
    h1=key%size
    return h1


def hashfunction2(key,size):
    for i in range(m):
        h2=(key+i*i)%m
        return h2


def hashtable(ht):
    print(f"\nHash Table    \tKey")
    for j in range(len(ht)):
        if ht[j]!=-1:
            print(f"\n{j}   \t->    \t{ht[j]}")
        else:
            print(f"\n{j}")


phone_database=telephone()
m=int(input("Enter size of hashtable:"))
hash_table=[-1]*m

opt=int(input("\nIf collision occurs choose any one collision technique:\n1.Linear Probing\n2.Quadratic Probing: "))

for k in phone_database:
    h1=hashfunction1(k,m)
    h2=hashfunction2(k,m)

    if hash_table[h1]==-1:
        hash_table[h1]=k
    else:
        if opt==1:
            while hash_table[h1]!=-1:
                h1+=1
            hash_table[h1]=k
        elif opt==2:
            for j in range(len(hash_table)):
                new_hash=(h1+j*j)%m
                if(hash_table[new_hash]==-1):
                    hash_table[new_hash]=k
                    break
hashtable(hash_table)
