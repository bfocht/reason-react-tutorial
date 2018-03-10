type item = {
    title: string,
    completed: bool
  };

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

/* `children` isn't used, therefore ignored.
    We ignore it by prepending it with an underscore */
let make = (_children) => {
    ...component,
  
    initialState: () => {items: []},
    reducer: (action, state) =>
      switch (action) {
      | AddItem => ReasonReact.Update({...state, items: [{title: "item", completed: false}, ...state.items]})
      },
  
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
                    List.map((item) => <TodoItem title=item.title completed=item.completed />, self.state.items)
                ))
            )
            </div>
        </div>;
    },
};