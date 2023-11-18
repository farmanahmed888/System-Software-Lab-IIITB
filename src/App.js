import Navbar from './Navbar';
import Footer from './Footer';
import Homepage from './Homepage';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom'
import Products from './Products';
import Account from './Account';
import Cart from './Cart';
import ProductDetail from './ProductDetail';
function App() {

  return (
    <Router>
      <div className="App">
        <Navbar></Navbar>
        <div className="content">
          <Switch>
            <Route exact path="/">
              <Homepage></Homepage>
            </Route>
            <Route exact path="/Products">
              <Products></Products>
            </Route>
            <Route exact path="/Account">
              <Account></Account>
            </Route>
            <Route exact path="/Cart">
              <Cart></Cart>
            </Route>
            <Route exact path="/ProductDetail">
              <ProductDetail></ProductDetail>
            </Route>
          </Switch>
        </div>
        <Footer></Footer>
      </div>
    </Router>
  );
}

export default App;
