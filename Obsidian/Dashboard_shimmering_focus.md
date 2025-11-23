Total file Count: `$=dv.pages().length`
```dataview
	TASK
	FROM "Calendar" or "Todo"
	WHERE !completed
	SORT text asc
```
> [!Linux]
> [[Linux Querks]]

> [!column] #### Semesters and Assignments
>> [!note] Semesters
>>```dataviewjs
>>let folderPath = `Uni/Semesters`; // Folder path 
>>
>>dv.table(["File Name", "Last Modified"], 
    >>dv.pages(`"${folderPath}"`) // Properly wrap the folder path in quotes
      >>.sort(p => p.file.name, 'asc') // Sort by last modified time
      >>.map(p => [p.file.link, p.file.mtime])
>>);
>>```
>
>> [!info] Unfinished Assignments
>> 
>>```dataviewjs
>>let folderPath = "Uni/Assignments"; // Define the folder to search
>>let coursesFolder = "Uni/Courses"; // Define the folder where course notes are stored
>>
>>// Get all course notes and map their file names to their links
>>let courseNotes = {};
>>let coursePages = dv.pages(`"${coursesFolder}"`);
>>
>>if (coursePages) {
    >>coursePages.forEach(course => {
        >>courseNotes[course.file.name] = course.file.link;
    >>});
>>}
>>
>>// Find all assignments in the folder that are incomplete (completed === false or missing)
>>let incompleteAssignments = dv.pages(`"${folderPath}"`)
    >>.where(p => p.completed !== true && p.completed !== "true") // Filter by incomplete status
    >>.sort(p => p.file.mtime, 'desc'); // Sort by last modified date
>>
>>// Display results in a table
>>dv.table(["Assignment", "Due Date", "Course", "Progress"], 
    >>incompleteAssignments.map(p => [
        >>p.file.link, // Assignment file link
        >>p.due_date ?? "No Due Date", // Due date or default text
        >>courseNotes[p.course] ?? "❌ Course Not Found", // Link to the course note or error message
        >>p.progress ?? "No Progress Info" // Display progress or fallback text
    >>])
>>);
>>```