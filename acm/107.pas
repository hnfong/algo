program p107;
var
	i,j : longint;
	i64,j64 : int64;
	k64 : int64;
begin
	for i := 1 to trunc(sqrt(1000000))+1 do
		for j := i+1 to 1000000 do begin
			{writeln('fsck', i,' ',j);}
			i64 := i;
			i64 := i64*i64;
			j64 := j;
			j64 := j64*j64;
			k64 := round(sqrt(i64+j64));
			k64 := k64*k64;
			if i64+j64=k64 then writeln(i,' ',j);
		end;
end.
