const WatchList = (props) => {
    const watches=props.watches;
    return (
        <div className="WatchList">
            {/*adding new stuff here test*/}
            {watches.map((watch) => (
                    <div className="row">
                        <div className="col-4" key={watch.id}>
                            <h4>{watch.title}</h4>
                            <p>{watch.cost}</p>
                        </div>
                    </div>
                ))}
                {/*adding new stuff here test*/}
        </div>
    );
}
 
export default WatchList;