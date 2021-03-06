srch='[+-]?[0-9]+$' #need to searching for integer

number=0 

#check if file exist
if [ ! -f numbers.txt ]
then
	echo 0 > numbers.txt
fi

for run in {1..50}
do

	#critical region starts

	#read file line by line
	while read line
	do
		#read each word in line
		for word in line
		do
			#find integer
			if [[ $word =~ srch ]]
			then
				#save it
				number=$word
			fi
		done
	done < numbers.txt

	((number++))
	echo $number >> numbers.txt

done

#citical region ends
