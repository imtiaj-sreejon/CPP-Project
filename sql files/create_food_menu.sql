create table food_menu(
	day varchar2(20),
	meal_time varchar2(20),
	items varchar2(100),
	constraints check_day check(day in ('saturday','sunday', 'monday', 'tuesday', 'wednesday', 'thursday', 'friday')),
	constraints check_meal_time check(meal_time in ('breakfast', 'lunch', 'dinner'))
);