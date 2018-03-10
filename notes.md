## Slide 20 sample reason code
```
type schoolPerson = Teacher | Director | Student(string);

let greeting = (stranger) =>
 switch (stranger) {
 | Teacher => "Hey professor!"
 | Director => "Hello director."
 | Student("Richard") => "Still here Ricky?"
 | Student(anyOtherName) => "Hey, " ++ anyOtherName ++ "."
 };

greeting(Teacher) |> Js.log;
greeting(Student("Bryan")) |> Js.log;
```

## Slide 21 install webpack
```
npm install webpack -D
npm install webpack-cli -D
npm install --save-dev webpack-dev-server -D
```

## Slide 24 Sample ReasonReact code
```
ReactDOMRe.renderToElementWithId(
    ReasonReact.stringToElement("hello, world!"),
    "root"
);
```

## Slide 26 Add types
```
type item = {
  title: string,
  completed: bool
};
```

## Slide 27 Add some state
```
/* State declaration */
type state = {
    items: list(item)
  };
  
/* Action declaration */
type action =
| AddItem;
  
/* Component template declaration.
Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("TodoApp");
```

wire up the the action to the onClick
```
render: self => {
        <div className="container">
            <h1 className="title"> (ReasonReact.stringToElement("Items to do: " ++ string_of_int(List.length(self.state.items)))) </h1>
            <button className="btn btn-primary" onClick=(self.reduce((_evt) => AddItem)) >
                (ReasonReact.stringToElement("Add Item"))
            </button>
            <hr />
            <div className="items">
                (ReasonReact.stringToElement("Nothing to do"))
            </div>
        </div>;
    },
```

```
render: self => {
        <div className="container">
            <h1 className="title"> (ReasonReact.stringToElement("Items to do: " ++ string_of_int(List.length(self.state.items)))) </h1>
            <button className="btn btn-primary" onClick=(self.reduce((_evt) => AddItem)) >
                (ReasonReact.stringToElement("Add Item"))
            </button>
            <hr />
            <div className="items">
                (
                    ReasonReact.arrayToElement(Array.of_list(
                        List.map((item) => ReasonReact.stringToElement(item.title), self.state.items)
                    ))
                )
            </div>
        </div>;
    },
```


```
<TodoItem ...item />
```
