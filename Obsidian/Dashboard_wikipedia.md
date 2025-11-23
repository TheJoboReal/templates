Total file Count: `$=dv.pages().length`

> See [[Software Documentation]] or jump to [[Project Tortuga|Getting started]]
> Also see [[All Hardware Bugs]] for all documented bugs on hardware, or [[All Software Bugs]] for all documented bugs on software.

## Tasks
> [!info] Create Content
>  ```meta-bind-button
> label: "New Object"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:b49b040b-fd3a-4d78-b7a0-bc6ba9713c71"
> ```
> ```meta-bind-button
> label: "New Robot"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:0f32744d-f376-4bd0-96f7-0f7fee38a6cf"
> ```
>
> ```meta-bind-button
> label: "New Robot Type"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:f439af74-5031-4ae6-824e-563c0d160237"
> ```
>
> ```meta-bind-button
> label: "New Note"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:281260e3-ccd1-4f97-92de-a61fc5753909"
> ```
>
> ```meta-bind-button
> label: "New Location"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:fe81ada2-701d-4187-9214-75ceccd6c05f"
> ```
>
> ```meta-bind-button
> label: "New Task"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:0cfb1e56-f58e-4b52-b3c4-e0ecec50c323"
> ```
>
> ```meta-bind-button
> label: "Rapport Hardware Bug"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:c1a5c71e-f621-41f0-b989-a769fbaa17be"
> ```
>
> ```meta-bind-button
> label: "Rapport Software Bug"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:38acf9e4-dae7-466a-9812-9ae32d551d38"
> ```

```dataviewjs
let tasks = dv.pages('"Data/Tasks"')
    .filter(p => !p.completed)
    .sort(p => p.dueDate, 'asc'); 

dv.table(["Tasks", "Priority" , "Due Date"], tasks.map(t => [t.file.link, t.priority, t.dueDate]));
```

---

## Robots
> [!info] Open Hardware Bugs
>```dataviewjs
>let folderPath = '"Data/Hardware Bugs"';
>dv.table(
>  ["Bugs", "Robot"],
>  dv.pages(folderPath)
>    .filter(p => p.closed !== true && p.closed !== "true")
>   .sort(p => p.file.date, 'asc')
>    .map(p => [p.file.link, p.robot])
>);
>```

> [!info] People
>
> ```meta-bind-button
> label: "New Person"
> icon: ""
> style: "primary"
> class: ""
> cssStyle: ""
> backgroundImage: ""
> tooltip: ""
> id: ""
> hidden: false
> actions:
>   - type: "command"
>     command: "quickadd:choice:bd29b097-3eae-4343-9909-8c357d90fa7e"
> ```
>
>```dataviewjs
>let folderPath = '"Data/People"';
>dv.table(
>  [""],
>  dv.pages(folderPath)
>   .sort(p => p.file.date, 'asc')
>    .map(p => [p.file.link])
>);
>```

```dataviewjs
let folderPath = "Data/Objects";

dv.table(
  ["Robot", "Robot Type"],
  dv.pages(`"${folderPath}"`)
    .where(p => p.object && p.object.toLowerCase() === "robot")
    .sort(p => p.file.name, 'asc')
    .map(p => [p.file.link, p.robot_type])
);

```

## Recent Files

```dataviewjs
let recentFiles = dv.pages('"Data"')  // Adjust this to your folder if needed
    .sort(p => p.file.mtime, 'desc')  // Sort by modification time (most recent first)
    .slice(0, 5);  // Get only the top 5

dv.table(["Recent Files", "Last Modified"], recentFiles.map(f => [f.file.link, f.file.mtime.toLocaleString()]));
```

