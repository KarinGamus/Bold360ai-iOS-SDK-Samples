// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import Foundation
import RealmSwift
import NanorepUI

class DBManager {
    
    private var database:Realm
    
    init() {
        database = try! Realm()
    }
    
    func getDataFromDB() -> Results<Item> {
        let results: Results<Item> =  database.objects(Item.self)
        return results
    }
    
    func addData(object: Item) {
        try! database.write {
            database.add(object, update: true)
            print("Added new object")
        }
    }
    
    func deleteAllDatabase()  {
        try! database.write {
            database.deleteAll()
        }
    }
    
    func deleteFromDb(object: Item) {
        try! database.write {
            database.delete(object)
        }
    }
}
