program p10364;
{
	@JUDGE_ID: 20044WC 10364 PASCAL "Recur"
}
var
	i,j,k : longint;
	n : longint;
	z : longint;
	ni,nt : longint;
	a : array[1..30] of longint;
	u : array[1..30] of boolean;
	q : boolean;
procedure recur(x,y:longint);
var i : longint;
begin
	if q then exit;
	if y > z div 4 then exit;
	u[x] := true;
	if y = (z div 4) then begin
		q := true;
		for i := 1 to n do if u[i] then a[i] := 0;
		exit;
	end;
	for i := x+1 to n do begin
		if not u[i] then recur(i,y+a[i]);
	end;
	u[x] := false;
end;

label nope;
label yup;
begin
	readln(nt);
	for ni := 1 to nt do begin
		read(n);
		for i := 1 to n do read(a[i]);
		readln;
		z := 0;
		for i := 1 to n do z := z + a[i];
		{writeln(z,', ',z div 4);}
		if z mod 4 > 0 then goto nope;
		for i := 1 to n do begin
			for j := i downto 2 do begin
				if a[j]>a[j-1] then begin
					k := a[j];
					a[j]:=a[j-1];
					a[j-1]:=k;
				end;
			end;
		end;
		for k := 1 to 4 do begin
			fillchar(u,sizeof(u),0);
			{for i := 1 to n do write(a[i]:3); writeln;}
			q := false ; recur(1,a[1]);
		end;
		q := true;
		for i := 1 to n do if a[i] > 0 then q := false;
		if q then goto yup;
		if not q then goto nope;
		nope: writeln('no'); continue;
		yup: writeln('yes'); continue;
	end;
end.
