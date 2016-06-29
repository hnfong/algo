program p10189;
{
	@JUDGE_ID: 20044WC 10189 PASCAL "DaP/DyP"
}
const
	hc : array[1..8,1..2] of integer = (
		(1,1),
		(1,0),
		(1,-1),
		(-1,1),
		(-1,0),
		(-1,-1),
		(0,1),
		(0,-1)
	);
var
	map : array[0..101,0..101] of char;
	v : array[0..101,0..101] of longint;
	a,b : longint;
	i,j,k : longint;
	testcase : longint;
begin
	testcase := 0;
	while true do begin
		inc(testcase);
		readln(a,b);
		if (a=0) and (b=0) then break;
		if testcase > 1 then writeln;
		fillchar(map,sizeof(map),'.');
		fillchar(v,sizeof(v),0);
		for i := 1 to a do begin
			for j := 1 to b do begin
				read(map[i,j]);
			end;readln;
		end;

		for i := 1 to a do begin
			for j := 1 to b do begin
				if map[i,j] = '*' then begin
					v[i,j] := 100;
				end;
				for k := 1 to 8 do begin
					if map[i+hc[k,1],j+hc[k,2]] = '*' then begin
						inc(v[i,j]);
					end;
				end;
			end;
		end;
		writeln('Field #',testcase,':');
		for i := 1 to a do begin
			for j := 1 to b do begin
				if v[i,j] < 100 then write(v[i,j]) else write('*');
			end;writeln;
		end;
	end;
end.
