program p369;
const
	sets : array[1..3,1..2] of longint = (
		(0,2),
		(3,8),
		(9,17)
	);
type
	dat = record
		r : shortint;
		o : array[1..2] of shortint;
	end;
var
	i,j,k : longint;
	w : array[0..1024*256] of dat;

procedure dump(s:longint);
var	i : longint;
begin
	for i := 0 to 17 do begin
		write( (s shr i) and 1,' ');
		if (i = 2) or (i = 8) or (i=17) then writeln;
	end;
end;

function process(s,a,b:Longint):longint;
var i :longint;
begin
	process := -1;
	for i := a to b do begin
		if (s shr i) and 1 = 1 then exit;
	end;
	for i := a to b do begin
		s := s or (1 shl i);
	end;
	process := s;
end;

function negamax(s:longint) : longint;
label hell;
var
	i,j,k,max,t,cache : longint;
	opt : array[1..2] of shortint;
begin
	if (w[s].r <> 0) then begin
		negamax := w[s].r;
		exit;
	end;
	
	if (s = 262143) then begin
		max := 1;
		opt[1]:=1;
		opt[2]:=1;
		goto hell;
	end;
	max := -99;
	for k := 1 to 3 do begin
		for i := sets[k,1] to sets[k,2] do begin
			for j := i to sets[k,2] do begin
				t := process(s,i,j);
				if t > -1 then begin
					cache := negamax(t);
					if -cache > max then begin
						max := -cache;
						opt[1] := i;
						opt[2] := j;
					end;
				end;
				if max = 1 then goto hell;
			end;
		end;
	end;
	if max = -99 then begin
		max := 0;
		writeln('error! draw?!');
	end;
	hell:
	w[s].r := max;
	w[s].o[1] := opt[1];
	w[s].o[2] := opt[2];
	negamax := max;
end;

begin
	fillchar(w,sizeof(w),0);
	writeln('loading...');
	negamax(0);
	writeln('done!');
	while true do begin
		k := 0;
		while k <> 262143 do begin
			dump(k);
			writeln('choose a move');
			readln(i,j);
			if (i = -1) and (j = -1) then exit;
			if (i = -1) or (j = -1) then break;
			while (process(k,i,j) = -1) do begin
				writeln('invalid move. again');
				readln(i,j);
			end;
			k := process(k, i,j);
			writeln(w[k].r, ' ', w[k].o[1], ' ', w[k].o[2]);
			k := process(k, w[k].o[1], w[k].o[2]);
		end;
		dump(k);
		writeln('Game Over.');
		writeln('Press enter to continue');
		readln;
	end;
end.

