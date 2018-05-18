CREATE or replace procedure check_smartcard(input_id in number, chk out number) as
	temp number;
begin
	select id into temp
	from smartcard_info
	WHERE student_id = input_id;
	chk:=temp;
	exception
	when no_data_found
	then chk:=0;
end;
/