import { Link } from "react-router-dom/cjs/react-router-dom.min";

const ProductDetail = () => {
    return (
        <div className="small-container single-product">
            <div className="row">
                {/*we have created 2 columns, one for the image and other for the text
      related to an image*/}
                <div className="col-2">
                    <img src={require("./img/gallery-1.jpg")} alt="gallery-1" width="100%" id="product-img" />
                    {/*id in bigger image so we can replace with its variants, so when we click on its different angle, it will show in large picture using JS*/}
                    <div className="small-img-row">
                        <div className="small-img-col">
                            <img src={require("./img/gallery-1.jpg")} alt="gallery-1" width="100%" className="small-img" />
                            {/*using class in all 4 small pictures so we can use them in JS and when we click on it, it show in larger picture*/}
                        </div>
                        <div className="small-img-col">
                            <img src={require("./img/gallery-2.jpg")} alt="gallery-2" width="100%" className="small-img" />
                        </div>
                        <div className="small-img-col">
                            <img src={require("./img/gallery-3.jpg")} alt="gallery-3" width="100%" className="small-img" />
                        </div>
                        <div className="small-img-col">
                            <img src={require("./img/gallery-4.jpg")} alt="gallery-4" width="100%" className="small-img" />
                        </div>
                    </div>
                </div>
                {/*column related to the text of single product*/}
                <div className="col-2">
                    <p>Home/ Watch</p>
                    <h1>Product</h1>
                    <h4>$50.00</h4>
                    {/*no of products*/}
                    <input type="number" defaultValue={1} />
                    <Link to="/Cart" className="btn">
                        Add To Cart
                    </Link>
                    {/*add to cart button*/}
                    <h3>
                        Product Details <i className="fa fa-indent" aria-hidden="true" />
                    </h3>
                    <br />
                    <p>
                        The Carl F. Bucherer Manero collection is home to an elegant set of
                        timepieces that takes its inspiration from the watches created by the
                        brand during the 50s and 60s. Be it the classic round case or the
                        perfect cocktail of dauphine hands with index markers, the Manero
                        collection is a timeless classic. A dress watch, the Manero collection
                        is also home to certain sports watches such as the Manero Flyback and
                        Manero Chronoperpetual.
                    </p>
                </div>
            </div>
        </div>

    );
}

export default ProductDetail;