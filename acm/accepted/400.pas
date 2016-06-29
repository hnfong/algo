program p400;
{
	@JUDGE_ID:  20044WC 400 PASCAL "(i > j) || (i < j) || (i == j)"
}
var
	i,j,k,n,c,l,r : longint;
	a : array[1..100] of string[61];
	t : string[61];
	out : array[1..100, 1..21] of string[61];
function validchar(x:char):boolean;
begin
	validchar := false;
	if (x >= 'A') and (x <= 'Z') then validchar := true;
	if (x >= 'a') and (x <= 'z') then validchar := true;
	if (x >= '0') and (x <= '9') then validchar := true;
	if (x = '.') then validchar := true;
	if (x = '_') then validchar := true;
	if (x = '-') then validchar := true;
end;

begin
	while not eof do begin
		fillchar(a,sizeof(a), 0);
		fillchar(out,sizeof(out), 0);
		l := 0;
		readln(n);
		
		for i := 1 to n do begin
			readln(a[i]);
			for j := 1 to length(a[i]) do begin
				if not validchar(a[i][j]) then break;
			end;
			a[i] := copy(a[i],1,j);
			if length(a[i]) > l then l := length(a[i]);
		end;
		
		{ bubble sort }
		for i := 1 to n do begin
			for j := i downto 2 do begin
				if a[j] < a[j-1] then begin
					t := a[j];
					a[j] := a[j-1];
					a[j-1] := t;
				end;
			end;
		end;
		
		for i := 1 to 60 do write('-'); writeln;
		
		c := (62 div (l+2));
		r := ((n-1) div c) + 1 ;
		for i := 1 to c do begin
			for j := 1 to r do begin
				out[j,i] := a[(j+(i-1)*r)];
			end;
		end;
		
		for i := 1 to r do begin
			for j := 1 to c do begin
				write(out[i,j]);
				if (length(out[i,j+1]) > 0) and (j <> c) then write(' ':(l+2-length(out[i,j])));
			end;
			writeln;
		end;
	end;	
end.		

