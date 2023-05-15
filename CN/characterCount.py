import random
sent=input("enter sentence ");
start = 0
end=0
packet_string = ""
while end<len(sent):
 power = random.randint(1,8)
 end += 2**power-1
 packet = str(2**power)+sent[start:end]
 start = end
 packet_string= packet_string + packet + "\n\n"
print(packet_string)
