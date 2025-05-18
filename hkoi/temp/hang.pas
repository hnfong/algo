var
i,j,k:integer;
inchar:char;
word:array[1..5]of string;
answer,guess:string;
begin
randomize;
word[1]:='see'; word[2]:='apple'; word[3]:='get'; word[4]:='pascal'; word[5]:='basic';
j:=0; k:=0; guess:='';
answer:=word[random(4)+1];
for i:=1 to length(answer) do guess:=guess+('-'); writeln(guess);
	while k<length(answer) do begin
		write('Enter a letter or "*" to end: ');
		readln(inchar);
		if inchar='*' then break;
		inc(j);
		for i:=1 to length(answer) do begin
			if (guess[i]='-') and (inchar=answer[i]) then begin
				guess[i]:=inchar; inc(k); write(guess[i]);
			end else begin
				write(guess[i]);
			end;
		end; writeln;
	end;
writeln('Number of trial is ',j);
end. 
