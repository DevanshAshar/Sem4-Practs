import random
file_pdf=input("enter sentence ");
start = 0
end=0
packet_string = ""
while end<len(file_pdf):
 power = random.randint(1,8)
 end += 2**power
 packet = str(2**power)+file_pdf[start:end]
 start = end
 packet_string= packet_string + packet + "\n\n"
print(packet_string)
